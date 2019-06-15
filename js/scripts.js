var toggle_traf = document.querySelector("#b1");
toggle_traf.addEventListener("click", show_traf);
var cur_tars = {
    firsttar: 0,
    months: 1
};
var summ = document.querySelector("#summ");
var shown = false;
var shm = false;


function show_traf() {
    if (!shown) {
        var tars = document.querySelector(".tars");
        tars.style.display = "flex";
        tars.style.opacity = "1";
        var cur_tar = document.querySelector("#ctar");
        cur_tar.style.opacity = "0";
        shown = true;
        toggle_traf.textContent = "Hide Tarifs"
    }
    else {
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
    for (let i = 0; i < all_tars.length; i++) {
        all_tars[i].style.border = "solid 2px";
    }
    var targ = event.target;
    targ.style.border = "solid green 4px";
    var price = targ.querySelector(".pr");
    //console.log(+price.textContent)
    cur_tars.firsttar = +price.textContent;
    recount();
}

function month(event) {
    var targ = event.target;
    if (targ == document.querySelector("#m1"))// I know that's a kostil' but time is short;
    {
        cur_tars.months = 1;
    }
    if (targ == document.querySelector("#m2")) {
        cur_tars.months = 6;
    }
    if (targ == document.querySelector("#m3")) {
        cur_tars.months = 12;
    }
    for (let i = 0; i < all_months.length; i++) {
        all_months[i].style.border = "none";
    }
    targ.style.border = "solid green 2px";
    recount();
}

function recount() {
    var sum;
    sum = 0;
    sum += cur_tars.firsttar;
    //console.log(cur_tars.months);
    sum = sum * cur_tars.months;
    summ.textContent = sum;
}

var all_tars = document.querySelectorAll(".box");
var all_months = document.querySelectorAll(".container div");

for (let i = 0; i < all_tars.length; i++) {
    all_tars[i].addEventListener("click", tarchange);
}

for (let i = 0; i < all_months.length; i++) {
    all_months[i].addEventListener("click", month)
}
