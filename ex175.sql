-- Left join means that Address table may not exit to a certain person

SELECT Person.FirstName, Person.LastName, Address.City, Address.State
FROM Person
LEFT JOIN Address
ON Person.PersonId = Address.PersonId