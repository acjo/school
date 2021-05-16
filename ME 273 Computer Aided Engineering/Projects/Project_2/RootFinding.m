%This is our root finding algorithm DO NOT UPDATE!!
function [root] = RootFinding(x,y)
%%Calculates the next guess
nextGuess = x - ((y-x)*Function3(x)) / ((Function3(y)-Function3(x)));
%%if the next guess is accurate nough it returns it
%%else it recurssively calls itself using the next bracket
%%which is found by determining what brackets x and y have a different sign
%%than 'nextGuess'

if abs((nextGuess - y)*(100/nextGuess)) > 0.00001
    if (Function3(nextGuess) > 0) && (Function3(x) > 0)
        root = RootFinding(y, nextGuess);
    else
        root = RootFinding(x, nextGuess);
    end
else
    root = nextGuess;
end
end