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

function validation(str)
{
    if(str.length < 5)
    {
        return false;
    }
    return true;
}

function checkMove(move, id, piece)
{
    // if the move was attack, piece is'nt null and order is like this: Ra1Bb1
    // for solve this, i write this function
    if(move === "")
    {
        move = piece + id;
    } else{
        move += id;
    }
    return move;
}