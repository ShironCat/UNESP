#!/usr/bin/python

import random
import time

class Quick(object):
    def particao(self, a, ini, fim):
        pivo = a[fim-1]
        start = ini
        end = ini
        for i in range(ini,fim):
            if a[i] > pivo:
                end += 1
            else:
                end += 1
                start += 1
                aux = a[start-1]
                a[start-1] = a[i]
                a[i] = aux
        return start-1

    def quickSort(self, a, ini, fim):
        if ini < fim:
            pp = self.randparticao(a, ini, fim)
            self.quickSort(a, ini, pp)
            self.quickSort(a, pp+1,fim)
        return a

    def randparticao(self,a,ini,fim):
        rand = random.randrange(ini,fim)
        aux = a[fim-1]
        a[fim-1] = a[rand]
        a[rand] = aux
        return self.particao(a,ini,fim)
q = Quick()

#Vetor ordenado
i = 50000
a = []
file = open("VetorOrdenado.txt", "w")
while(i < 100000):
    for j in range(0, i):
        a.append(j)
    clockAntes = time.clock()
    q.quickSort(a, 0, len(a))
    clockDepois = time.clock()
    file.write("{}\n".format(str(clockDepois - clockAntes)))
    i += 2000
file.close()

#Vetor desordenado
i = 50000
a = []
file = open("VetorDesordenado.txt", "w")
while(i < 100000):
    for j in range(0, i):
        a.append(random.randrange(0, i))
    clockAntes = time.clock()
    q.quickSort(a, 0, len(a))
    clockDepois = time.clock()
    file.write("{}\n".format(str(clockDepois - clockAntes)))
    i += 2000
file.close()

#Vetor ordenado ao contrario
i = 50000
a = []
file = open("VetorOrdenadoContrario.txt", "w")
while(i < 100000):
    for j in range(0, i):
        a.append(i - j)
    clockAntes = time.clock()
    q.quickSort(a, 0, len(a))
    clockDepois = time.clock()
    file.write("{}\n".format(str(clockDepois - clockAntes)))
    i += 2000
file.close()