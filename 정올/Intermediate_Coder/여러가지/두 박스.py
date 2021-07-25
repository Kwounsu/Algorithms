import sys
input = sys.stdin.readline


a,b,c,d = map(int, input().split())
e,f,g,h = map(int, input().split())

if (a==g and b==h) or (a==g and d==f) or (c==e and b==h) or (c==e and d==f):
    print("POINT")
elif c < e or d < f or g < a or h < b:
    print("NULL")
elif (e-c)*(f-d) == 0 or (g-a)*(h-b) == 0:
    print("LINE")
else:
    print("FACE")
