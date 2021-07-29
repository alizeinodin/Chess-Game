function recognizePiece(str) {
    str = str.toString();

    if(str === "")
    {
        return "";
    }
//    console.log(typeof(str));

    var array = str.split("/");
    var dataStr = array[3].split(".");
    return dataStr[0];
}
