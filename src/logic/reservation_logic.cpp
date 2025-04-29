

#include "reservation_logic.h"

void insert_reservation(Reservation const& reservation, std::vector<Reservation>& reservations, std::vector<std::string> const& stops)
{
    /// Fügt eine Reservierung in eine Liste bestehender Reservierungen ein.
    /// Erwartet die Reservierung und die Liste der bisherigen Reservierungen
    /// sowie eine Liste von Haltestellen.
    /// Die Liste der Reservierungen wird so sortiert, dass die Reihenfolge der Start-Orte
    /// und Ziel-Orte der Reihenfolge der Haltestellen entspricht.
    /// Sollte dies nicht möglich sein, wird die Reservierung nicht hinzugefügt
    /// und die liste der Reservierungen bleibt unverändert.
    
    


    // TODO
}

Reservation get_next_reservation(std::vector<Reservation> const& reservations, std::string const& next_stop, std::vector<std::string> const& stops)
{
    // TODO

    return Reservation();
}

bool is_valid_for_route(Reservation const& reservation, std::vector<std::string> const& stops)
{
    // TODO

    return true;
}
