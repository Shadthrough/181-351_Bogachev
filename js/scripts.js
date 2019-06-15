var toggle_traf = document.querySelector("#b1");
toggle_traf.addEventListener("click", show_traf);
var cur_tars = {
    firsttar: 0
};
var summ = document.querySelector("#summ");
var shown = false;

function show_traf() {
    if (!shown) {
        var tars = document.querySelector(".tars");
        tars.style.display = "auto";
        tars.style.opacity = "1";
        var cur_tar = document.querySelector("#ctar");
        cur_tar.style.opacity = "0";
        shown = true;
        toggle_traf.textContent = "Hide Tarifs"
    }
    else
    {
        var tars = document.querySelector(".tars");
        tars.style.display = "none";
        tars.style.opacity = "0";
        var cur_tar = document.querySelector("#ctar");
        cur_tar.textContent = "Changed";
        cur_tar.style.opacity = "1";
        toggle_traf.textContent = "Show Tarifs";
        shown = false;
    }
}

function tarchange(event) {
    var targ = event.target;
    targ.style.border = "solid green 4px"
    var price = targ.querySelector(".pr");
    cur_tars.firsttar = +price.data;
    recount();
}

function recount() {
    var sum;
    sum = 0;
    sum += cur_tars.firsttar;
    summ.textContent = sum;
}

var all_tars = document.querySelectorAll(".box");

for (let i = 0; i < all_tars.length; i++) {
    all_tars[i].addEventListener("click", tarchange);
}
