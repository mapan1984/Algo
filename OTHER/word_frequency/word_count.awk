BEGIN {
    print "Input words, EOF end input."
}

{
    count[$1]++
}

NF != 1 {
    e++
    print "bad word count in line", NR
}

END {
    print "Word count result:"
    for (word in count)
        print word, count[word]
}
