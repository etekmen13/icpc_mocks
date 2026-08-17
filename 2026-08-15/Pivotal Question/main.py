s = "101" + ' '.join([f"{i}" for i in range(100)])
print(s)
with open("tests/4.ans", "w+") as f:
  f.write(s)
  f.write('\n')