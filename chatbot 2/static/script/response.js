function getBotResponse(input) {
    //rock paper scissors
    input=input.toLowerCase();
    if (input == "admission") {
        return "visit:- 'www.siksha.com'";
    } else if (input == "counselling") {
        return "in which class you are";
    } else if (input == "college") {
        return "good visit:- 'www.siksha.com'";
    }



    // Simple responses
    if (input == "hello"||input=="hi"||input=="hii") {
        return "Hello there!, how can i help you!!";
    } else if (input == "goodbye") {
        return "Talk to you later!";
    } else {
        return "Try asking something else!";
    }
}