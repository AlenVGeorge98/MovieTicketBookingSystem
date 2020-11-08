/**
* @file movie.h
* Movie Ticket Booking Application
*
*/
#ifndef __MOVIE_H__
#define __MOVIE_H__

/// @private
struct movie_details
{
    int movie_code;
    char movie_name[60];
    char show_timing[10];
    char release_date[20];
    int ticket_price;
    int seat_no;
};

/// @private
extern struct movie_details m;

/**
*  Function to validate admin login
* @param[in] admin_username
* @param[in] admin_password
* @return '1' if login is successful, '0' if not.
*/
int admin_login(char *admin_username, char *admin_password);
/**
*  Function for admin to add movies
* @param[in] movie_code
* @param[in] movie_name
* @param[in] show_timing
* @param[in] release_date
* @param[in] ticket_price
* @param[in] seats
* @return "Movie Details Added Successfully" if the details are successfully stored in file.
*/

char* add_movies(int movie_code, char *movie_name, char *show_timing, char *release_date, int ticket_price, int seats);
/**
*  Function for registration of new users
* @param[in] fullname
* @param[in] username
* @param[in] password
* @param[in] mobile_no
* @return "User Registration Successful" if user details are stored successfully
*/
char* user_reg(char *fullname, char*username, char *password, char*mobile_no);

/**
*  Function for admin to view all the bookings of the theatre
* @return '0' if all bookings are displayed along with summary
*/
int view_bookings();



/**
*  Function for login of existing users
* @param[in] username
* @param[in] username
* @return Pass/Fail status of user login
*/
char* user_login(char *username, char *password);

/**
*  Function for users to view the list of movies
* @return '0' if list of movies added by the admin are displayed
*/
int view_movies();

/**
*  Function for users to book movie tickets
* @param[in] movie
* @param[in] seat
* @return Ticket for the movie containing the details of the show as well as the user
*/
char *book_tickets(char*movie, int seat);

/**
*  Function for users to search movie by name
* @param[in] m_name
* @return Details of movie if available
*/
char* search(char* m_name);

/**
*  Function for users to view the booked tickets
* @return Tickets if the user has booked tickets
*/
char *view_booked();


#endif // __MOVIE_H__

