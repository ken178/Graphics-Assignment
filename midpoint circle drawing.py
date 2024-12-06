#Import the necessary libraries
import matplotlib.pyplot as plt
from tabulate import tabulate

"""
#. Fuction to draw and generate the circle coordnates using
#. Midpoint Circle Drawing Algorithm
"""
def draw_circle(center_x, center_y, radius):
    x = radius
    y = 0
    p = 1.25 - radius  # Updated decision parameter

    # Initialize lists to store the coordinates
    coordinates = []

    # Plot the initial points in all octants
    while x >= y:
        coordinates.extend([(x + center_x, y + center_y),
                            (y + center_x, x + center_y),
                            (-x + center_x, y + center_y),
                            (-y + center_x, x + center_y),
                            (-x + center_x, -y + center_y),
                            (-y + center_x, -x + center_y),
                            (x + center_x, -y + center_y),
                            (y + center_x, -x + center_y)])

        y += 1
        if p <= 0:
            p = p + 2*y + 1
        else:
            x -= 1
            p = p + 2*y - 2*x
            + 1

    plt.plot(*zip(*coordinates), 'ro')  # Plot the circle

    # Set aspect ratio to 'equal' to ensure it appears as a complete circle
    plt.axis('equal')

    plt.grid()

    # Display the circle coordinates in a table
    table = tabulate(coordinates, headers=['X', 'Y'], tablefmt='fancy_grid')
    print(table)

    plt.show()

if __name__ == "__main__":
    # Take the radius and center coordinates from the user.
    radius = int(input("Enter the radius of the circle: "))
    center_x = int(input("Enter the x_center of the circle: "))
    center_y = int(input("Enter the y_center of the circle: "))

    # Function call
    draw_circle(center_x, center_y, radius)