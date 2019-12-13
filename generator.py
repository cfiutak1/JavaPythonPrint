

f = open("Util.java", "w")

java_types = [
    "boolean",
    "char",
    "byte",
    "short",
    "int",
    "long",
    "float",
    "double"
]

class_start = """
public class Util \t\t\t\t\t\t\t\t\t\t{

"""

f.write(class_start)

method_template = """
\tpublic static void print(
\t\t%s
\t) \t\t\t\t\t\t\t\t\t\t\t{
\t\t\t\t\t\t\t\t\t\t\t\t/*
\t\t\"\"\"
\t%s
\t\t\"\"\"
\t\t\t\t\t\t\t\t\t\t\t\t*/
\t%s
\t\t\t\t\t\t\t\t\t\t\t\t}
"""


for java_type in java_types:
    for i in range(64):
        parameters = ["arg" + str(j) for j in range(i + 1)]
        method_signature = [java_type + " " + param for param in parameters]
        method_signature_formatted = ",\n\t\t".join(method_signature)

        method_docstring = ("\tPrints the %ss %s\n" % (java_type, " ".join(parameters)))
        method_docstring += "\n\t\tArgs:\n"

        method_body = ""

        for param in parameters:
            print_lines = """\tSystem.out.print(%s)\t\t\t\t\t\t\t\t;\n\t\tSystem.out.print(" ")\t\t\t\t\t\t\t\t;
            """ % param

            method_body += print_lines
            method_docstring += "\t\t\t%s (%s): %s to be printed.\n" % (param, java_type, java_type)

        method_docstring += "\n\t\tReturns:\n\t\t\tNone"
        f.write(method_template % (method_signature_formatted, method_docstring, method_body))
f.write("\t\t\t\t\t\t\t\t\t\t\t\t}")

f.close()

