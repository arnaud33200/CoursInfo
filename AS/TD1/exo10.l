%%

(https?|ftp|ws):"//"([[:alnum:]]*".")*[[:alnum:]]*("/"[^ \n]*)*"/"? { ECHO; }
. {}
