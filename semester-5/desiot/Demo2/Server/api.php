<?php

header("Content-type: application/json");

$host = "localhost";
$username = "root";
$password = "";
$dbName = "desiot";

try {
    $conn = new mysqli($host, $username, $password, $dbName);
} catch (Exception $e) {
    http_response_code(500);
    echo json_encode([
        "message" => "Database connection failed",
    ]);

    exit();
}

$queries = [];
parse_str($_SERVER["QUERY_STRING"], $queries);

if ((!(isset($queries["api_key"])) || $queries["api_key"] !== getenv("API_KEY")) && $_SERVER["REQUEST_METHOD"] !== "GET") {
    http_response_code(401);
    echo json_encode([
        "message" => "Unauthorized",
    ]);

    exit();
}

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $json = file_get_contents("php://input");

    $data = json_decode($json, true);

    if (!(isset($data["id"]) && isset($data["value"]))) {
        http_response_code(400);
        echo json_encode([
            "message" => "id and value are required",
        ]);
        exit();
    }

    $id = $data["id"];
    $value = $data["value"];

    $query = "SELECT * FROM sensors WHERE id = '$id'";
    $result = $conn->query($query);
    if ($result->num_rows > 0) {
        $sql = "INSERT INTO sensor_data (sensor_id, value) VALUES ('$id', $value)";
        $result = $conn->query($sql);
        if ($result) {
            http_response_code(200);
            echo json_encode([
                "value" => $value,
            ]);
        } else {
            http_response_code(500);
            echo json_encode([
                "message" => "Data insertion failed",
            ]);
        }
    } else {
        http_response_code(404);
        echo json_encode([
            "message" => "Sensor not found",
        ]);
    }
} elseif ($_SERVER["REQUEST_METHOD"] === "GET") {
    $limit = isset($queries["limit"]) ? $queries["limit"] : 10;
    $page = isset($queries["page"]) ? $queries["page"] : 1;

    if (isset($queries["id"]) || isset($queries["sensor_name"])) {
        $id = $queries["id"] ?? null;
        $sensor_name = $queries["sensor_name"] ?? null;
        $query = "SELECT * FROM sensors WHERE id = '$id'";
        $result = $conn->query($query);
        if ($result->num_rows > 0) {
            if ($id){
                $query =
                    "SELECT sensor_data.*, sensors.name, locations.latitude, locations.longitude, sensor_types.name as type FROM sensor_data INNER JOIN sensors ON sensor_data.sensor_id = sensors.id INNER JOIN locations ON sensors.location_id = locations.id INNER JOIN sensor_types ON sensors.sensor_type_id = sensor_types.id WHERE sensor_data.sensor_id = '$id' ORDER BY sensor_data.id DESC LIMIT $limit OFFSET " .
                    ($page - 1) * $limit;
            } else {
                $query =
                    "SELECT sensor_data.*, sensors.name, locations.latitude, locations.longitude, sensor_types.name as type FROM sensor_data INNER JOIN sensors ON sensor_data.sensor_id = sensors.id INNER JOIN locations ON sensors.location_id = locations.id INNER JOIN sensor_types ON sensors.sensor_type_id = sensor_types.id WHERE sensors.name = '$sensor_name' ORDER BY sensor_data.id DESC LIMIT $limit OFFSET " .
                    ($page - 1) * $limit;
            }
            $result = $conn->query($query);
            $totalData = $conn
                ->query(
                    "SELECT COUNT(*) FROM sensor_data WHERE sensor_id = '$id'"
                )
                ->fetch_row()[0];

            $data = [];

            while ($row = $result->fetch_assoc()) {
                unset($row["sensor_id"]);
                $data[] = $row;
            }
            http_response_code(200);
            echo json_encode([
                "data" => $data,
                "page" => intval($page),
                "limit" => $limit,
                "totalData" => intval($totalData),
                "totalPage" => ceil($totalData / $limit),
            ]);
        } else {
            http_response_code(404);
            echo json_encode([
                "message" => "Sensor not found",
            ]);
        }
    } else {
            $query =
            "SELECT sensor_data.*, sensors.name, locations.latitude, locations.longitude, sensor_types.name as type FROM sensor_data INNER JOIN sensors ON sensor_data.sensor_id = sensors.id INNER JOIN locations ON sensors.location_id = locations.id INNER JOIN sensor_types ON sensors.sensor_type_id = sensor_types.id ORDER BY sensor_data.id DESC LIMIT $limit OFFSET " .
            ($page - 1) * $limit;
        $result = $conn->query($query);
        $totalData = $conn
            ->query("SELECT COUNT(*) FROM sensor_data")
            ->fetch_row()[0];

        $data = [];

        while ($row = $result->fetch_assoc()) {
            $data[] = $row;
        }
        http_response_code(200);
        echo json_encode([
            "data" => $data,
            "page" => intval($page),
            "limit" => $limit,
            "totalData" => intval($totalData),
            "totalPage" => ceil($totalData / $limit),
        ]);
    }
} else {
    http_response_code(405);
}
?>
