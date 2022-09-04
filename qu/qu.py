with open('./result1.txt','r',encoding='utf-8') as f:
	for line in f:
		#去除'//''
		a = line.split('//',1)[-1]
		if ":" in a:
			a = a.split(':',1)[0]
			with open('result.txt','a') as f:
				f.write(a+"\r")
		else:
			with open('result.txt','a') as f:
				f.write(a)
print('ok')
