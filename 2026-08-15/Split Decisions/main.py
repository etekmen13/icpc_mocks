from collections import Counter
n_words = int(input())
words = []
for i in range(n_words):
    words.append(input())

pairs = []
for i in range(n_words):
  for j in range(i+1, n_words):
      diff = [ord(c1) - ord(c2) for c1,c2 in zip(words[i], words[j])]

      for k in range(len(diff)):
        candidate = None
        if (diff[k] != 0 and candidate == None):
            if k + 1 >= len(diff) or diff[k+1] == 0:
               break
            if k + 2 < len(diff) and diff[k+2] != 0:
               break
            candidate = [words[i][k:k+2], words[j][k:k+2]]
        if candidate is not None:
          pairs.append(''.join(sorted(candidate)))

unique_pairs = Counter(pairs)
print(len([k for k, v in unique_pairs.items() if v == 1]))
   
               
          
         
         