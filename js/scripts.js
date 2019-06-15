var toggle_traf = document.querySelector("#b1");
toggle_traf.addEventListener("click", show_traf);
var cur_tars = {
    firsttar : 0
};
var summ = 0;

function show_traf() {
    var tars = document.querySelector(".tars");
    tars.style.display = "auto";
    tars.style.opacity = "1";
    var cur_tar = document.querySelector("#ctar");
    cur_tar.style.opacity = "0";
}

function tarchange(event) {
    var targ = event.target;
    var price = targ.querySelector(".pr");
    recout();
}

function recount() {
    
}

var all_tars = document.querySelectorAll(".tars .box");

for (let i = 0; i < all_tars.length; i++) {
    all_tars[i].addEventListener("click", tarchange);   
}
