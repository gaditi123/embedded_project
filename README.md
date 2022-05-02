# Deriving complete Data flow graphs (DFG) of processor/system modules
**Input** - Verilog code which is **well formatted** using standard Verilog formatting libraries/softwares in a **.txt file** <br />
**Output** - The graph is produced using Graphviz, which is a graphing software that can be used along with C++, Python etc. To produce the graph, the nodes, edges etc are specified in Graphviz format in a .dot who's written to via our original code. Using text-editor software libraries for Graphviz visulisation (`VS-CODE` - `Graphviz (dot) language support for Visual Studio Code` in our case) to visulize the graph. <br />
**Requirements** - 
- Text Editing Software like Vs-Code
- Graphviz visulisation extension installed into the text editing software
- Verilog Code 

## Data Flow Graph(DFG)
A data-flow graph is a collection of arcs and nodes in which the nodes are either places where variables are assigned or used, and the arcs show the relationship between the places where a variable is assigned and where the assigned value is subsequently used.<br /><br />

- In this project the DFG is implemented through parsing a .txt file containing a well formatted Verilog code. It program iterates through each line of the verilog code and ignores a choosen set of key words which are not relevent to the making of DGF. The words include - `{"module", "reg", "initial", "$display", "end", "endmodule", "wire", "input", "output"}`
- Further using if-else statements with the conditions to identify whether the line corresponds to a simple value assignment like - `dataG = 06;` or it an equation like - `S1 = dataG & dataS;`
- Once these statements are identified, we breakup the words based on spacing and ignore the last semicolon. Through list of space separted words we identify the _operators, operands and the answer variables_. For each line of verilog code, we create write to the output Graphviz file translating the code into nodes and edges notation to show how the data is being transferred and changed in the Verilog program. 
- Using map we convert operators which are of _string_ data type to their UNICODE values so that they can be displayed on the graph. 
- Finally using `helper function` the equations are writtern to the output Graphviz file, combining the 2 operators, 1 operand and 1 answer variable for each equation. The interconnection of various variables is maintained and how 1 variable/value can be used in different equations is also written to the output file to be shown in the DFG graph subsequently produced. 

<img width="463" alt="image" src="https://user-images.githubusercontent.com/56929057/166191236-ed11b55c-cb62-4a69-bea6-b67c1abd60cc.png">


## Control Flow Graph(CFG)

## Combined results of data flow and control flow graph

