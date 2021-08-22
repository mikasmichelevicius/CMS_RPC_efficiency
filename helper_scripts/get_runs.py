
my_file = open("run_list.txt", "r")

content = my_file.read()

content_list = content.split()

content_list = [e[3:9] for e in content_list]

print(content_list)
print(len(content_list))

#content_list.remove("321305")

#content_list.remove("324293")
#content_list.remove("324980")
# content_list.remove("324970")
#content_list.remove("321475")
#content_list.remove("320917")
# content_list.remove("321457")
content_list.remove("322022")
content_list.remove("324878")
content_list.remove("322179")

print(len(content_list))
count = 0
with open("runs_to_get.txt", "w") as output:
    for item in content_list:
        output.write("%s\n" % item)
