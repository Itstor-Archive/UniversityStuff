$(document).ready(function () {
    $('.slide').slick({
        infinite: true,
        speed: 500,
        arrows: true,
        cssEase: 'ease',
        draggable: false,
        swipe: false,
        touchmove: false
    });
});

$('.slide').on('beforeChange', function (event, slick, currentSlide, nextSlide) {
    if (nextSlide == 0) {
        var animate = () => {
            $("#name").glitch({
                chars: "&#*+%?£@§$",
                finalText: "About Me"
            });
        }
        animate();
    }
    if (nextSlide == 1) {
        var animate = () => {
            $("#name").glitch({
                chars: "&#*+%?£@§$",
                finalText: "My Work"
            });
        }
        animate();
    }
    if (nextSlide == 2) {
        var animate = () => {
            $("#name").glitch({
                chars: "&#*+%?£@§$",
                finalText: "Contact"
            });
        }
        animate();
    }
    // console.log(nextSlide)
});