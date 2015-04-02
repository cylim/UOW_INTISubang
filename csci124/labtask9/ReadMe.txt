
You are required to write a program using linked-list to keep track of the patients who come to a clinic to get treatment. The linked-list should keep the patient’s name and also a number to indicate the priority. The priority value is either 0 or 1. 

When a patient arrives at the clinic, the patient’s name is added to the end of the linked list. If the patient does not need emergency treatment, the priority should be set to 0 and the record is added to the end of the list. Otherwise, the priority is set to 1 and the record is added to the front of the linked-list.

The first patient in the list will always consult the doctor first. When a patient is sent to consult the doctor, the patient’s name is removed from the linked-list.

Your program should provide options to either admit a patient or remove a patient from the list. Your program should also allow all the patients’ name in the list to be printed.