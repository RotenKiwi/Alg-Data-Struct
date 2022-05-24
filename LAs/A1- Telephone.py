table, tableq={},{} #initialised tables for linear and quadratic probing
totl, totq=0,0      #size of the tables


def create(b):
    for i in range(b):      #fill both tables with null value
        table[i]= -1
        tableq[i]= -1


def linsert(key,b):     #insert function for linear probing
    global totl
    hash=key%b          #hash function
    flag=0
    if table[hash]== -1:
        table[hash]=key
    else:
        for i in range(0,b):
            hash=(key+i)%b
            if table[hash]== -1:
                table[hash]=key
                totl+=1
                flag+=1
                break
    if flag==0:
        print("Table Full or Key not Probed")


def qinsert(key,b):     #insert function for quadratic probiing
    global totq
    hash=key%b          #hash function
    flag=0
    if tableq[hash]==-1:
        tableq[hash]=key
    else:
        for i in range(0,b):
            hash = (key+(i*i))%b
            if tableq[hash]==-1:
                tableq[hash]=key
                totq += 1
                flag += 1
                break
        if flag == 0:
            print("Table Full or Key not probed.")


def lsearch(key,b):     #search function for linear probing
    hash=key%b
    flag=0
    if table[hash]==-1:
        print(key, "is not present.")
    else:
        for i in range(0,b):
            hash=(key+i)%b
            if table[hash]== -1:
                print(key, "is not present.")
                flag+=1
                break
            elif table[hash]==key:
                print(key, "is present at location ", hash)
                flag+=1
                break
        if flag==0:
            print(key, "is not present.")


def qsearch(key,b):         #search function for linear probing
    hash=key%b
    flag=0
    if tableq[hash]== -1:
        print(key, "is not present.")
    else:
        for i in range(0,int((b-1)/2)):
            hash=(key+(i*i))%b
            if tableq[hash]== -1:
                print(key, "is not present.")
                flag+=1
                break
            elif tableq[hash]==key:
                print(key, "is present at location ", hash)
                flag+=1
                break
        if flag==0:
            print(key, "is not present.")


def printtable(b):          #function for printing the tables
    print("\n linearly probed: ")
    for i in range(b):
        print(table[i], end="|")
    print("\n Quadratically probed: ")
    for i in range(b):
        print(tableq[i], end="|")
    print(" ")
    

b=int(input("Enter table size"))
create(b)
while(1):
    print("1. Linear probing")
    print("2. Quadratic probing")
    print("3. Exit")
    ch=int(input("\n Enter choice: "))

    if ch==1:
        while(1):
            print("\n 1. Insert")
            print("2. Search")
            print("3. Exit")
            ch2=int(input("Enter Choice"))

            if ch2==1:
                if totl==b:
                    print("Table is already full")
                else:
                    key=int(input("Enter the phone number: "))
                    linsert(key,b)
            elif ch2==2:
                key=int(input("Enter the phone number: "))
                lsearch(key,b)
            elif ch2==3:
                print("Exit")
                break
                printtable(b)
    elif ch==2:
        while(1):
            print("\n 1. Insert")
            print("2. Search")
            print("3. Exit")
            ch2=int(input("Enter Choice"))

            if ch2==1:
                if totq==b:
                    print("Table is already full")
                    print(totq)
                else:
                    key=int(input("Enter the phone number: "))
                    qinsert(key,b)
            elif ch2==2:
                key=int(input("Enter the phone number: "))
                qsearch(key,b)
            elif ch2==3:
                print("Exit")
                printtable(b)
                break
    elif ch==3:
        print("exit")
        break