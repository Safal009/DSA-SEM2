table,tableq = {},{}
totl,totq = 0,0


def create(b):
  for i in range(b):
    table[i] = -1
    tableq[i] = -1
    
def linsert(key,b):
  global totl
  hash = key%b
  flag = 0 
  if table[hash]==-1:
    table[hash]=key
  else:
    for i in range(0,b):
      hash = (key+i)%b
      if table[hash]==-1:
        table[hash]=key
        totl += 1
        flag += 1
        break
    if flag == 0:
      print("Table Full or Key not probed.")
      
def qinsert(key,b):
  global totq
  hash = key%b
  flag = 0 
  if tableq[hash]==-1:
    tableq[hash]=key
  else:
    for i in range(0,int((b-1)/2)):
      hash = (key+(i*i))%b
      if tableq[hash]==-1:
        tableq[hash]=key
        totq += 1
        flag += 1
        break
    if flag == 0:
      print("Table Full or Key not probed.")
      
      
def lsearch(key,b):
  hash = key%b
  flag = 0 
  if table[hash]==-1:
    print("Key : ",key," is not present.")
  else:
    for i in range(0,b):
      hash = (key+i)%b
      if table[hash]==-1:
        print("Key : ",key," is not present.")
        flag += 1
        break
      elif table[hash]==key:
        print("Key : ",key," is present at location : ",hash)
        flag += 1
        break
    if flag == 0:
      print("Key : ",key," is not present.")
      
      
def qsearch(key,b):
  hash = key%b
  flag = 0 
  if tableq[hash]==-1:
    print("Key : ",key," is not present.")
  else:
    for i in range(0,int((b-1)/2)):
      hash = (key+(i*i))%b
      if tableq[hash]==-1:
        print("Key : ",key," is not present.")
        flag += 1
        break
      elif tableq[hash]==key:
        print("Key : ",key," is present at location : ",hash)
        flag += 1
        break
    if flag == 0:
      print("Key : ",key," is not present.")
      
      
def printtable(b):
  print("\nLinearly Probed Table :")
  for i in range(b):
    print(table[i],end=" | ")
  print("\n\nQuadratically Probed Table :")
  for i in range(b):
    print(tableq[i],end=" | ")
  print("")



b = int(input("Enter the table size : "))
create(b)
while(1):
  print("1.Linear Probing")
  print("2.Quadratic Probing")
  print("3.Exit")
  ch = int(input("\nEnter the choice: "))
  
  if ch==1:
    while(1):
      print("\n1.Insert")
      print("2.Search")
      print("3.Exit")
      ch2 = int(input("\nEnter the choice : "))
    
      if ch2==1:
        if totl==b:
          print("The table is already full . ")
        else:
          key = int(input("Enter the phone number : "))
          linsert(key,b)
      elif ch2==2:
        key = int(input("Enter the phone number to be searched: "))
        lsearch(key,b)
      elif ch2==3:
        print("Exit")
        break
      printtable(b)
  elif ch==2:
    while(1):
      print("1.Insert")
      print("2.Search")
      print("3.Exit")
      ch2 = int(input("\nEnter the choice : "))
      
      if ch2==1:
        if totq==b:
          print("The table is already full . ")
        else:
          key = int(input("Enter the phone number : "))
          qinsert(key,b)
      elif ch2==2:
        key = int(input("Enter the phone number to be searched : "))
        qsearch(key,b)
      elif ch2==3:
        print("Exit")
        break
      printtable(b)
  elif ch==3:
    print("Exit")
    printtable(b)
    break
  else:
    printtable(b)
