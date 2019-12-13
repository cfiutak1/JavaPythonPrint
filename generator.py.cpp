#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string s = "\n"
               "\n"
               "f = open(\"Util.java\", \"w\")\n"
               "\n"
               "java_types = [\n"
               "    \"boolean\",\n"
               "    \"char\",\n"
               "    \"byte\",\n"
               "    \"short\",\n"
               "    \"int\",\n"
               "    \"long\",\n"
               "    \"float\",\n"
               "    \"double\"\n"
               "]\n"
               "\n"
               "class_start = \"\"\"\n"
               "public class Util \\t\\t\\t\\t\\t\\t\\t\\t\\t\\t{\n"
               "\n"
               "\"\"\"\n"
               "\n"
               "f.write(class_start)\n"
               "\n"
               "method_template = \"\"\"\n"
               "\\tpublic static void print(\n"
               "\\t\\t%s\n"
               "\\t) \\t\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t{\n"
               "\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t/*\n"
               "\\t\\t\\\"\\\"\\\"\n"
               "\\t%s\n"
               "\\t\\t\\\"\\\"\\\"\n"
               "\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t*/\n"
               "\\t%s\n"
               "\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t}\n"
               "\"\"\"\n"
               "\n"
               "\n"
               "for java_type in java_types:\n"
               "    for i in range(64):\n"
               "        parameters = [\"arg\" + str(j) for j in range(i + 1)]\n"
               "        method_signature = [java_type + \" \" + param for param in parameters]\n"
               "        method_signature_formatted = \",\\n\\t\\t\".join(method_signature)\n"
               "\n"
               "        method_docstring = (\"\\tPrints the %ss %s\\n\" % (java_type, \" \".join(parameters)))\n"
               "        method_docstring += \"\\n\\t\\tArgs:\\n\"\n"
               "\n"
               "        method_body = \"\"\n"
               "\n"
               "        for param in parameters:\n"
               "            print_lines = \"\"\"\\tSystem.out.print(%s)\\t\\t\\t\\t\\t\\t\\t\\t;\\n\\t\\tSystem.out.print(\" \")\\t\\t\\t\\t\\t\\t\\t\\t;\n"
               "            \"\"\" % param\n"
               "\n"
               "            method_body += print_lines\n"
               "            method_docstring += \"\\t\\t\\t%s (%s): %s to be printed.\\n\" % (param, java_type, java_type)\n"
               "\n"
               "        method_docstring += \"\\n\\t\\tReturns:\\n\\t\\t\\tNone\"\n"
               "        f.write(method_template % (method_signature_formatted, method_docstring, method_body))\n"
               "f.write(\"\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t\\t}\")\n"
               "\n"
               "f.close()\n"
               "";    
    
    ofstream outputFile;
    outputFile.open("generator.py");    
    outputFile << s; 
    outputFile.close();   
    return 0;
}
