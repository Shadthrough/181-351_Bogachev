var toggle_traf = document.querySelector("#b1");
toggle_traf.addEventListener("click", show_traf);

function show_traf() {
    var tars = document.querySelector(".tars");
    tars.style.display = "auto";
    tars.style.opacity = "1";
    var cur_tar = document.querySelector("#ctar");
    cur_tar.style.opacity = "0";
}