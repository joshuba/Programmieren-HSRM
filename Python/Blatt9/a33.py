#!user/bin/python3


#LIST COMPREHENSION
#geradzahligen Kubikzahlen der Zahlen 1 bis 10,
print([x**3 for x in range(1, 11) if x % 2 == 0])


#aller Teiler einer Zahl z außer 1 und z, also Zahlen, durch die z ohne Rest teilbar ist (testen Sie mit 123, 12345, 123456)
z = 123456
print([y for y in range(2, z) if z % y == 0])


#is_prime = lambda y: [x for x in range(2, y) if y % x == 0]

#aller Primzahlen zwischen 10000 und 10100
print([y for y in range(10000, 10101) if len([x for x in range(2, y) if y % x == 0]) == 0])


print("\n")


#FUNKTIONALE PRIMITIVE   #funktionalen Primitive map() und filter() ohne List-Comprehension
#geradzahligen Kubikzahlen der Zahlen 1 bis 10,
print(list(filter(lambda x: x%2 == 0, map(lambda x: x**3, range(1, 11)))))



#aller Teiler einer Zahl z außer 1 und z, also Zahlen, durch die z ohne Rest teilbar ist (testen Sie mit 123, 12345, 123456)
aa = 123456
print(list(filter(lambda y: aa % y == 0, range(2, aa))))


#aller Primzahlen zwischen 10000 und 10100
print(list(filter(lambda x: not list(filter(lambda y: x % y == 0, range(2, x))), range(10000, 10101))))
