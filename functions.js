function recognize(str) {
    str = str.toString();

    if(str === "")
    {
        return "";
    }

    var array = str.split("/");
    return array;
}
// this function return address of image
// in this program this function convert QUrl to string that can read with qml
function recognizeImg(str)
{
    var myLocation = "media/";
    var array = str.split("/");
    myLocation += array[2] + "/";
    myLocation += array[3];
    return myLocation;

}

function validation(str)
{
    if(str.length < 4)
    {
        return false;
    }
    return true;
}

function checkMove(move, id, piece)
{
    // if the move was attack, piece is'nt null and order is like this: Ra1Bb1
    // for solve this, i write this function
//    if(move === "")
//    {
//        move = piece + id;
//    } else{
//        move += id;
//    }
    move += piece + id;
    console.log("MOVE--> ", move);
    return move;
}

function indexCell(id)
{
    const array = ["a", "b", "c", "d", "e", "f", "g", "h"];
    for(var i = 0; i < array.length; i++) {
        if(id.includes(array[i]))
        {
            return i;
        }
    }
}
