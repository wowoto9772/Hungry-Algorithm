src = open("./solution.cpp", "r");
dat = open("./tistory.out", "w");

header = '<pre class = "line-numbers"><code class = "language-cpp">'
footer = '</code></pre>'

dat.writelines(header)

while True:
	linedata = src.readline()

	if not linedata: break

	out_line = ""

	for c in linedata:
		if c == '<':
			out_line += "&lt;"	
		elif c == '>':
			out_line += "&gt;"
		else:
			out_line += c;

	dat.writelines(out_line)

dat.writelines(footer)

src.close()
dat.close()
