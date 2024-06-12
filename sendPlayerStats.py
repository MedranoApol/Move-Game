import mysql.connector as mysql
import csv

def getValuesFromCSV(fileName : str) -> dict:
    # intializes csv dictionary
    csv_values = {}

    # Open the CSV file
    with open(f"{fileName}", newline="") as csvfile:
        # Create a CSV reader object
        reader = csv.DictReader(csvfile)

        # Read the first (and only) row
        row = next(reader)

        # Loop through each header and its corresponding value
        for header, value in row.items():
            # Store the value in the dictionary, only if it's not already present
            if header not in csv_values or csv_values != value:
                csv_values[header] = value

    return csv_values

def main() -> None:
    connection = mysql.connect(host="localhost", user="root", password="", database="move_game")

    if connection.is_connected():
        print("\t\t\t Thank you for playing!")
    else:
        print('Failed to connect')
        exit()

    mycursor = connection.cursor()

    d = getValuesFromCSV("resultsOfGame.csv")

    mycursor.execute("INSERT INTO playerresults VALUES (DEFAULT, %s, %s, %s, %s, %s, %s, %s, %s)", (d['name'], d['map_width'], d['map_height'], d['num_moves'], d['num_items'], d['enemy_def'], d['ally_met'], d['date']))
    connection.commit()
        
    connection.close()

# runs the main function
if __name__ == "__main__":
    main()