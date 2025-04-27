#ifndef COACH_H
#define COACH_H

#include "display.h"
#include <unordered_map>
#include <vector>

/// Ein Wagen (Coach) repräsentiert einen Wagen eines Zuges.
/// Diese Klasse enthält Informationen über die Sitzplatz-Konfiguration
/// sowie die vorhandenen Displays und deren Inhalte.
struct Coach {
    /// Decken-Displays im Wagen.
    std::vector<Display> ceiling_displays;

    /// Sitzplatz-Displays im Wagen.
    std::unordered_map<std::string, Display> seat_displays;

    /// Standard-Konstruktor, erzeugt ein Coach-Objekt ohne Sitze und Displays.
    Coach();

    /// Fügt ein Decken-Display hinzu.
    void addCeilingDisplay(Display const& display);
    
    /// Fügt ein Sitzplatz-Display hinzu.
    void addSeatDisplay(std::string const& seatId, Display const& display);

    /// Aktualisiert den Text aller Decken-Displays.
    void updateCeilingDisplays(std::string const& newText);

    /// Aktualisiert den Text eines Sitzplatz-Displays.
    /// Gibt eine Fehlermeldung aus, wenn der Sitzplatz nicht existiert.
    void updateSeatDisplay(std::string const& seatId, std::string const& newText);

    /// Zeigt alle Decken-Displays an.
    void showCeilingDisplays() const;

    /// Zeigt alle Sitzplatz-Displays an.
    void showSeatDisplays() const;

    /// Zeigt alle Displays an (Decken- und Sitzplatz-Displays).
    void showAllDisplays() const;
};

#endif
