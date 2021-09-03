import math

Ax, Ay, Bx, By, Cx, Cy, Dx, Dy = map(float, input().split())

Ilen = math.sqrt((Ax - Cx) ** 2 + (Ay - Cy) ** 2)
Flen = math.sqrt((Bx - Dx) ** 2 + (By - Dy) ** 2)
Kx = Bx + Cx - Ax - Dx
Ky = By + Cy - Ay - Dy

Klen = math.sqrt(Kx ** 2 + Ky ** 2)
if Klen > 10 ** (-6) and 0 < (Kx*(Cx - Ax) + Ky*(Cy - Ay)) / Klen ** 2 < 1:
    print(math.fabs(Kx * (Cy - Ay) + Ky * (Ax - Cx)) / Klen)
else: print(min(Ilen, Flen))