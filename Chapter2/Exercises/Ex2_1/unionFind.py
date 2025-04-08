from random import randint, seed


test_cases = [1000, 10000, 100000, 1000000]

def test_case(n):
    id = [i for i in range(n)]
    sz = [1 for i in range(n)]

    p = randint(0, n -1)
    q = randint(0, n -1)

    n_edges = 1
    n_unions = 0
    while n_unions < n - 1:
        i = p
        #print(f"Performing find for {i}")
        while(i != id[i]):
            id[i] = id[id[i]]
            i = id[i]
        j = q
        #print(f"Performing find for {j}")
        while(j != id[j]):
            id[j] = id[id[j]]
            j = id[j]
        if (i != j):
            n_unions += 1

            if (sz[i] < sz[j]):
                tmp = i
                i = j
                j = tmp
            id[j] = id[i]
            sz[i] += sz[j]

        p = randint(0, n - 1)
        q = randint(0, n - 1)
        n_edges += 1
    print(f"N: \t{n}\tEdges: {n_edges}")

def main():
    for i in test_cases:
        seed()
        test_case(i)

if __name__ == "__main__":
    main()
