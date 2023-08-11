#!/usr/bin/bash

create_emp(){
    read -p "Employee name: " name
    read -p "Employee Number : " number
    read -p "Employee Designation: " designation
    echo $name":"$number":" + $designation >> employee.txt
}

echo "Menu:"
echo "1. Create Employee Record "
echo "2. Delete Employee Record"
echo "3. search Employee Record"
echo "4. Display Employee Record"
echo "5. Sort  Employee Record"
echo "6. List ALL Records Employee Record"
echo "7. Exit Employee Record"
echo "Enter the choice (1-7):"
read choice
echo $choice

case $choice in
    1)
    echo "creating" 
    create_emp
    ;;
esac