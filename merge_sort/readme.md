### merge sort

    merge (left, right)
    
    merge_sort(list):
        if list.length == 1:
            return
        else
            might = list.length / 2
            left, right = list[0..might], list[might..]
            merge_sort(left)
            merge_sort(right)
            merge(left, right)
