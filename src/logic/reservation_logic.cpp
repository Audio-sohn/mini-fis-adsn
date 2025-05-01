

#include "reservation_logic.h"
#include <algorithm>


//================================================================================================================================================
void insert_reservation(Reservation const& reservation, std::vector<Reservation>& reservations, std::vector<std::string> const& stops)
//================================================================================================================================================
{

    //------------------------------------------------------------------------
    // sanitization
    //------------------------------------------------------------------------
    
    if (!is_valid_for_route(reservation, stops))
    {
        return;
    }
    
    //------------------------------------------------------------------------
    // liste kopieren und reservation einfügen, leere liste instanziieren
    //------------------------------------------------------------------------
    
    std::vector<Reservation> reservations_copy = reservations;
    reservations_copy.push_back(reservation);
    std::vector<Reservation> reservations_sorted{};
    Reservation ONGR{"",""}; // ONGR = ongoing reservation
    
    //------------------------------------------------------------------------
    // sortierte liste aufbauen
    //------------------------------------------------------------------------
    
    // iterieren durch stops
    for (auto stop : stops) 
    {
        // reservation hat inhalt UND noch gültig?
        if (ONGR.to != "" && stop != ONGR.to)
        {
            continue;
        }

        // reservation verfallen!
        ONGR = {};

        // nächste reservation?
        for (auto res : reservations_copy)
        {
            if (stop == res.from)
            {
                // einfügen
                reservations_sorted.push_back(res);
                ONGR = res;
            }
        }
    }
    
    //------------------------------------------------------------------------
    // originalliste mit sortierter liste vergleichen und ggf ersetzten
    //------------------------------------------------------------------------
    
    if (reservations_copy.size() == reservations_sorted.size())
    {
        reservations = reservations_sorted;
        return;
    }
    return;


    // es wird anfänglich nach der ersten reservation gesucht, deren "from"
    // dem aktuellen stop entspricht. diese wird an reservations angehängt
    
    // dann wird die iteration mit leerlauf geführt bis "to" der aktuellen 
    // reservation erreicht ist

    // ab dann wird nach der nächsten reservation gesucht für die gilt:
    // "from" == (aktueller)stop, diese wird wieder an die liste angehängt

    // wurden die stops durchiteriert,  dann ist die sortierte liste aufgebaut

    // sind die listen immer noch gleich lang, dann konnten alle reservations 
    // eingeordnet werden. wenn nicht, failt der 
}

//================================================================================================================================================
Reservation get_next_reservation(std::vector<Reservation> const& reservations, std::string const& next_stop, std::vector<std::string> const& stops)
//================================================================================================================================================
{


    //----------------------------------------------------------------------------
    // iterieren durch stops, von "next_stop" aus, suche in reservations nach stop
    //----------------------------------------------------------------------------
    auto ns_in_stops = std::find(stops.begin(), stops.end(), next_stop);

    for (auto i = ns_in_stops ; i < stops.end() ; i++)
    {   
        for (auto res : reservations)
        {
            if (res.to == *i)
            {
                return res;
            }
        }

    }

    return Reservation{};
}

//================================================================================================================================================
bool is_valid_for_route(Reservation const& reservation, std::vector<std::string> const& stops)
//================================================================================================================================================
{
     
    //----------------------------------------------------------------------------
    // stops werden nach "from" und "to" durchsucht, fundreihenfolge wird geprüft 
    //----------------------------------------------------------------------------
    bool fromFound = false;
    bool toFound = false;
    
    for (auto const &stop : stops) 
    {
        fromFound = stop == reservation.from ? true : fromFound;
        toFound = stop == reservation.to ? true : toFound;
        
        // wenn "to" VOR "from" gefunden wurde, abbrechen und false returnen
        if (toFound && !fromFound)
        {
            return false;
        }
    }

        // wurden beide gefunden?
        return toFound && fromFound;

}
