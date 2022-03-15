BEGIN {
    print "Input words, EOF end input."
}

{
    for (i = 1; i <= NF; i++) {
        # print i, $i
        count[$i]++
    }
}

END {
    print "Word count result:"
    for (word in count)
        print word, count[word]
}
