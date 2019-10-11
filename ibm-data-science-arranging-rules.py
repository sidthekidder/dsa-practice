#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'arrangingRules' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts STRING_ARRAY rules as parameter.
#
import pandas as pd

def support(df, attributes):
    # [('age', 'Senior'), ('gender', 'male')]
    x1 = df
    for attr in attributes:
        x1 = x1[df[attr[0]] == attr[1]]

    x1_count = x1.count()[0]
    x2_count = df.count()[0]

    return float(x1_count) / float(x2_count)

def confidence(df, rule):
    # split on arrow
    rule_left = rule.split('=>')[0]
    rule_right = rule.split('=>')[1]
    
    # remove curly braces first and last char
    rule_left = rule_left[1:-1]
    rule_right = rule_right[1:-1]

    # split on comma
    left_rules = rule_left.split(',')
    right_rules = rule_right.split(',')
    
    # split into attributes
    left_rules_list = [(lr.split('=')[0],lr.split('=')[1])  for lr in left_rules]
    right_rules_list = [(rr.split('=')[0],rr.split('=')[1]) for rr in right_rules]

    xy_list = list(set(left_rules_list).union(set(right_rules_list)))

    support_XY = support(df, xy_list)
    support_X = support(df, left_rules_list)

    return float(support_XY) / float(support_X)

def arrangingRules(rules):
    with open('census.csv', 'r') as f:
        contents = f.read().splitlines()

    headers = ['age', 'sex', 'education', 'native-country', 'race', 'marital-status', 'workclass', 'occupation', 'hours-per-week', 'income', 'capital-gain', 'capital-loss']
    contents = [item.split(',') for item in contents]
    newcontents = []
    for line in contents:
        line = [record.split('=')[1] for record in line]
        newcontents.append(line)
    
    contents = newcontents
    df = pd.DataFrame(contents)
    df.columns = headers

    # for each rule, find confidence and save to new list
    newrules = []
    for rule in rules:
        conf = confidence(df, rule)
        newrules.append((rule, conf))

    newrules.sort(key = lambda t: -t[1])
    newrules = [item[0] for item in newrules]
    return newrules
