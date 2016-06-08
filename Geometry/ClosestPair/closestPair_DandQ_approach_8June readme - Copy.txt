0. Presort X and Y
1. Divide point in 2 halves.
2. Find smallest of two halved recursively say it d.
3. Make a strip and take point in it where distance of strip from POINTmiddle <= d.
4. return min(d, min_length_point_in_strip)
5. O(n*log n)