import cv2   
import os
import pytesseract
import pyperclip
import sys

path = '/'.join(sys.argv[0].split('/')[0:-1]) + '/'

image = cv2.imread(path + 'tmp.png')
cropped = image[2:50, 2:-1] 
Problem_Name = pytesseract.image_to_string(cropped)

Name_vector = Problem_Name.split()
Problem_Name = ' '.join(Name_vector[1:])
Name_vector[0] = Name_vector[0][:-1]
Image_Number = int(Name_vector[0])
Name_vector[1] = str(Image_Number) + '-' + Name_vector[1]
Name_vector.pop(0)
Image_Name = '_'.join(Name_vector)

with open(path + f"../{str(Image_Number)}.cpp", 'w') as f:
	f.write(pyperclip.paste())
cv2.imwrite(path + f"../{Image_Name}.png", image)
os.remove(path + 'tmp.png')

text = []
with open(path +'../../README.md', 'r') as f:
	text = f.readlines()
	LeetCode = False
	string_num = 0
	for string_num, line in enumerate(text):
		if 'LeetCode' in line:
			LeetCode = True
		if LeetCode and line.startswith('|') and line.split('|')[1].isdigit():
			number = int(line.split('|')[1])
			if (number > Image_Number):
				text.insert(string_num, f'|{Image_Number}|{Problem_Name}|C++|Done|\n')
				break;
				
				
with open(path +'../../README.md', 'w') as f:
	text = "".join(text)
	f.write(text) 
