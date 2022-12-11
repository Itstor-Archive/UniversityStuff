<?php
  $queries = [];
  parse_str($_SERVER["QUERY_STRING"], $queries);
  $limit = isset($queries["limit"]) ? $queries["limit"] : 10;
  $page = isset($queries["page"]) ? $queries["page"] : 1;
  $id = $queries["id"] ?? null;
?>

<html>
  <head>
    <title>IoT Dashboard</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="https://cdn.tailwindcss.com"></script>
    <script src="https://cdn.jsdelivr.net/npm/chart.js@3.9.1/dist/chart.min.js"></script>   
  </head>
  <body class="bg-gray-900 py-24 px-24">
      <div class="flex justify-center items-center flex-col">
        <div class="overflow-x-auto relative shadow-md sm:rounded-lg">
          <table class="w-full text-sm text-left text-gray-500 dark:text-gray-400">
            <thead class="text-xs text-gray-700 uppercase bg-gray-50 dark:bg-gray-700 dark:text-gray-400">
              <tr>
              <th scope="col" class="py-3 px-6">Name</th>
              <th scope="col" class="py-3 px-6">Type</th>
              <th scope="col" class="py-3 px-6">Value</th>
              <th scope="col" class="py-3 px-6">Location</th>
              <th scope="col" class="py-3 px-6">Published at</th>
              </tr>
            </thead>
            <tbody id="sensor-data">
            </tbody>
          </table>
        </div>
        <div id="chart" class="m-8" style="width:600px; display: flex; gap: 24px; flex-direction:column">
        </div>
      </div>
  </body>
  <script>
      var chartColor = [];

      function randomColor(){
        color = "hsl(" + Math.random() * 360 + ", 100%, 75%)";
        return color;
      }

    function getSensorData(limit, page) {
      var xhttp = new XMLHttpRequest();

      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          var response = JSON.parse(this.responseText);
          var data = response.data;
          var html = "";
          for (var i = 0; i < data.length; i++) {
            html += '<tr class="bg-white border-b dark:bg-gray-800 dark:border-gray-700 hover:bg-gray-50 dark:hover:bg-gray-600">';
            html += '<td scope="row" class="py-4 px-6 font-medium text-gray-900 whitespace-nowrap dark:text-white">' + data[i].name + '</td>';
            html += '<td class="py-4 px-6">' + data[i].type + '</td>';
            html += '<td class="py-4 px-6">' + data[i].value + '</td>';
            html += '<td class="py-4 px-6">' + data[i].latitude + ',' + data[i].longitude + '</td>';
            html += '<td class="py-4 px-6">' + data[i].timestamp + '</td>';
            html += '</tr>';
          }
          document.getElementById("sensor-data").innerHTML = html;

          var chartContainer = document.getElementById("chart"); 
          
          if (chartColor.length == 0) {
            for (var i = 0; i < data.length; i++) {
              chartColor.push(randomColor());
            }
          }

          if (chartContainer.hasChildNodes()) {
            chartContainer.innerHTML = "";
          }

          dataset = data.reduce(function (r, a) {
              r[a.sensor_id] = r[a.sensor_id] || [];
              r[a.sensor_id].push(a);
              return r;
          }, Object.create(null));

          Object.entries(dataset).forEach(function (value, key) {
            chartContainer.appendChild(document.createElement("canvas"));
            var ctx = document.querySelectorAll("canvas")[key];
            ctx.classList.add("rounded-lg");

            var myChart = new Chart(ctx, {
              type: 'line',
              color: 'white',
              data: {
                labels: value[1].map(function (item) {
                  return item.timestamp;
                }).reverse(),
                datasets: [{
                  label: value[1][0].name,
                  data: value[1].map(function (item) {
                    return item.value;
                  }).reverse(),
                  backgroundColor: chartColor[key],
                  borderColor: chartColor[key],
                  borderWidth: 2
                }]
              },
              plugins: [{
                beforeDraw: function (chart) {
                  const {ctx} = chart;
                  ctx.save();
                  ctx.globalCompositeOperation = 'destination-over';
                  ctx.fillStyle = '#1f2937';
                  ctx.fillRect(0, 0, chart.width, chart.height);
                  ctx.restore();
                },
              }],
              options: {
                plugins: {
                  legend: {
                    labels: {
                      color: 'white'
                    }
                  },
                },
                animation: {
                    duration: 0
                },
                scales: {
                  y: {
                    beginAtZero: true,
                    grid:{
                      color: 'rgba(255, 255, 255, 0.1)'
                    },
                    ticks: {
                      color: 'white'
                    }
                  },
                  x: {
                    ticks: {
                      color: 'white'
                    }
                  },
                },
              }
            });
          });
        }
      };
      <?php
      if ($id){
        echo '
          xhttp.open("GET", "api.php?id='.$id.'&limit=" + limit + "&page=" + page, true);
          ';
      }
        else {
          echo '
          xhttp.open("GET", "api.php?limit=" + limit + "&page=" + page, true);
          ';
        }
      ?>
      xhttp.send();
    }
    window.onload = function() {
      getSensorData(<?php echo $limit; ?>, <?php echo $page; ?>);
    }

    setInterval(function() {
      getSensorData(<?php echo $limit; ?>, <?php echo $page; ?>);
    }, 2000);
  </script>
</html>