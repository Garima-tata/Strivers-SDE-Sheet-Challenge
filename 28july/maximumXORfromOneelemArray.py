def maxXorQueries(nums, queries):
    nums.sort()
    queries = sorted((m, x, i) for i, (x, m) in enumerate(queries))
    result = [-1] * len(queries)
    trie = {}
    k = 0
    for m, x, i in queries: 
        # If the element <= m_i and not the end, then add it to the Trie
        while k < len(nums) and nums[k] <= m: 
            def add_number(x):
                current = trie
                for bit in format(x, '032b'):
                    if bit not in current:
                        current[bit] = {}
                    current = current[bit]
                current['value'] = x
                return

            add_number(nums[k])
            k += 1

        if trie: 
            def find_best_match(x):
                current = trie
                for bit in format(x, '032b'):
                    reverse_bit = '0' if bit == '1' else '1'
                    if reverse_bit in current:
                        current = current[reverse_bit]
                    else:
                        current = current[bit]
                return current['value']

            result[i] = x ^ find_best_match(x)

    return result
