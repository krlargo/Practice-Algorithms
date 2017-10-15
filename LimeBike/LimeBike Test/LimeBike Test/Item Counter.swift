//
//  Item Counter.swift
//  LimeBike Test
//
//  Created by Kevin Largo on 10/11/17.
//  Copyright © 2017 Kevin Largo. All rights reserved.
//

import Foundation

class ItemCounter {
    // MARK: - Internal Structs
    struct Ride {
        var startTime: NSDate;
        var endTime: NSDate;
        var bikeBasketItems: [Item];
    }
    
    struct Item {
        var name: String; // e.g. apples, brownie, carrots, diamonds
        var count: Int;
        
        init(_ name: String, count: Int) {
            self.name = name;
            self.count = count;
        }
    }
    
    class TimeInterval {
        var startTime: Int;
        var endTime: Int;
        var items: [Item];
    }
    
    // MARK: - Variables
    var timeIntervals = [Int](); // Sorted collection of all startTimes & endTimes
    
    // MARK: - Functions
    func process_ride(_ ride: Ride) {
        let startTime = ride.startTime;
        let endTime = ride.endTime;
        
        if(!timeIntervals.contains(startTime)) {
            timeIntervals.append(startTime);
        }
        
        if(!timeIntervals.contains(endTime)) {
            timeIntervals.append(endTime);
        }
        
        timeIntervals.sort(by: <);
    }
    
    func print_items_per_interval() {
        for i in 0 ..< timeIntervals.count-1 {
            let startTime = timeIntervals[i];
            let endTime = timeIntervals[i+1];
            print("\(startTime)-\(endTime) -> ");
        }
    }
}
