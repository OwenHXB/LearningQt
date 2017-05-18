#!/usr/bin/env python
# -*- coding: utf-8 -*-
import string
import shlex

data = []
with open('map.txt') as f:
    for line in f.readlines():
        line = line.strip()
        lineWords = shlex.split(line)
        # print len(lineWords) - 1
        if len(lineWords) > 0 and string.find(lineWords[0], "data:") != -1:
            lineWords[1] = lineWords[1][1:]
            lineWords[-1] = lineWords[-1][:-1] + ','
            for lineWord in lineWords[1:]:
                data.append((int)(lineWord[:-1]))
            # data = []


print len(data)
# for x in data:
    # if x != -1:
        # print x,
