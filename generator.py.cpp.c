#include <stdio.h>

const char *out =
"#include <iostream>\n\
#include <fstream>\n\
\n\
using namespace std;\n\
\n\
int main() {\n\
    string s = \"\n\"\n\
               \"\n\"\n\
               \"f = open(\"Util.java\", \"w\")\n\"\n\
               \"\n\"\n\
               \"java_types = [\n\"\n\
               \"    \"boolean\",\n\"\n\
               \"    \"char\",\n\"\n\
               \"    \"byte\",\n\"\n\
               \"    \"short\",\n\"\n\
               \"    \"int\",\n\"\n\
               \"    \"long\",\n\"\n\
               \"    \"float\",\n\"\n\
               \"    \"double\"\n\"\n\
               \"]\n\"\n\
               \"\n\"\n\
               \"class_start = \"\"\"\n\"\n\
               \"public class Util \t\t\t\t\t\t\t\t\t\t{\n\"\n\
               \"\n\"\n\
               \"\"\"\"\n\"\n\
               \"\n\"\n\
               \"f.write(class_start)\n\"\n\
               \"\n\"\n\
               \"method_template = \"\"\"\n\"\n\
               \"\tpublic static void print(\n\"\n\
               \"\t\t%s\n\"\n\
               \"\t) \t\t\t\t\t\t\t\t\t\t\t{\n\"\n\
               \"\t\t\t\t\t\t\t\t\t\t\t\t/*\n\"\n\
               \"\t\t\"\"\"\n\"\n\
               \"\t%s\n\"\n\
               \"\t\t\"\"\"\n\"\n\
               \"\t\t\t\t\t\t\t\t\t\t\t\t*/\n\"\n\
               \"\t%s\n\"\n\
               \"\t\t\t\t\t\t\t\t\t\t\t\t}\n\"\n\
               \"\"\"\"\n\"\n\
               \"\n\"\n\
               \"\n\"\n\
               \"for java_type in java_types:\n\"\n\
               \"    for i in range(64):\n\"\n\
               \"        parameters = [\"arg\" + str(j) for j in range(i + 1)]\n\"\n\
               \"        method_signature = [java_type + \" \" + param for param in parameters]\n\"\n\
               \"        method_signature_formatted = \",\n\t\t\".join(method_signature)\n\"\n\
               \"\n\"\n\
               \"        method_docstring = (\"\tPrints the %ss %s\n\" % (java_type, \" \".join(parameters)))\n\"\n\
               \"        method_docstring += \"\n\t\tArgs:\n\"\n\"\n\
               \"\n\"\n\
               \"        method_body = \"\"\n\"\n\
               \"\n\"\n\
               \"        for param in parameters:\n\"\n\
               \"            print_lines = \"\"\"\tSystem.out.print(%s)\t\t\t\t\t\t\t\t;\n\t\tSystem.out.print(\" \")\t\t\t\t\t\t\t\t;\n\"\n\
               \"            \"\"\" % param\n\"\n\
               \"\n\"\n\
               \"            method_body += print_lines\n\"\n\
               \"            method_docstring += \"\t\t\t%s (%s): %s to be printed.\n\" % (param, java_type, java_type)\n\"\n\
               \"\n\"\n\
               \"        method_docstring += \"\n\t\tReturns:\n\t\t\tNone\"\n\"\n\
               \"        f.write(method_template % (method_signature_formatted, method_docstring, method_body))\n\"\n\
               \"f.write(\"\t\t\t\t\t\t\t\t\t\t\t\t}\")\n\"\n\
               \"\n\"\n\
               \"f.close()\n\"\n\
               \"\";    \n\
    \n\
    ofstream outputFile;\n\
    outputFile.open(\"generator.py\");    \n\
    outputFile << s; \n\
    outputFile.close();   \n\
    return 0;\n\
}";


int
main(int argc, char **argv) {
	FILE *gfile;

	gfile = fopen("generator.py.cpp", "w");

	fprintf(gfile,"%s\n", out);

	fclose(gfile);
	return 0;
}
