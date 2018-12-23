
public enum VehicleType {
	Standard
}

public class PriorityComparator implements Comparator<ParkingSpot> {
	@Override
	public int compare(ParkingSpot ps1, ParkingSpot ps2) {
		if(ps1.levelId == ps2.levelId) {
			return ps1.spotId - ps2.spotId;
		} else if {
			return ps1.levelId - ps2.levelId;
		}
	}
}

public class ParkingSpot {
	private Vehicle vehicle;
	int levelId;
	int spotId;
	int spotSize;
	boolean isAvailable;
	ParkingSpot(int levelId, int spotId, int spotSize) {
		this.spotId = spotId;
		this.levelId = levelId;
		this.spotSize = spotSize;
		this.isAvailable = true;
	}

}

public Interface ParkingSpotStrategy {
	public ParkingSpot findParkingSpot(Vehicle v);
}

public class ParkingQueueStrategy implements ParkingSpotStrategy{
	Queue<ParkingSpot> smallVehicleQue = new LinkedList<>;
	Queue<ParkingSpot> largeVehicleQue = new LinkedList<>;
	HashMap<String, ParkingSpot> locationMap = new HashMap<>();
	ParkingQueueStrategy(DatabaseInstance dbInstance) {

	}
	public ParkingSpot findParkingSpot(Vehicle v) {

	}
}


public class ParkingPriorityQueueStrategy implements ParkingSpotStrategy{
	PriorityQueue<ParkingSpot> smallParkingSpots = new PriorityQueue<ParkingSpot>();
	PriorityQueue<ParkingSpot> largeParkingSpots = new PriorityQueue<ParkingSpot>();
	HashMap<String, ParkingSpot> locationMap = new HashMap<>();
	ParkingQueueStrategy(DatabaseInstance dbInstance) {
		
	}	
	public ParkingSpot findParkingSpot(Vehicle v) {
		
	}
}

public class ParkingLot {
	ParkingSpotStrategy strategy;
	ParkingLot(DatabaseInstance dbInstance, ParkingSpotStrategy strategy) {
		this.strategy = strategy(dbInstance);
	}

	public boolean parkVehicle(Vehicle v) {

	}

	public void releaseParkingSpot(Vehicle v) {

	}

}


public class ParkingLot {
	Queue<ParkingSpot> smallVehicleQue = new LinkedList<>;
	Queue<ParkingSpot> largeVehicleQue = new LinkedList<>;
	HashMap<String, ParkingSpot> locationMap = new HashMap<>();
	ParkingLot(DatabaseInstance dbInstance) {
		//load
	}

	public boolean parkVehicle(Vehicle v) {

	}

	public void releaseParkingSpot(Vehicle v) {

	}

}


public class ParkingLotController {

	ParkingLot parkingLotInstance = null;
	ParkingLotFactory(DatabaseInstance dbInstance, ParkingSpotStrategy strategy) {
		parkingLotInstance = new ParkingLot(dbInstance, strategy);
	}

	public boolean vehicleEntry(Vehicle v) {
		parkingLotInstance.parkVehicle(v);
	}

	public void vehicleExit(Vehicle v) {
		parkingLotInstance.releaseParkingSpot(v);
	}

}
class App {
	psvm() {

	}
}

public abstract class Vehicle {
	protected String licensePlate;
	protected VehicleType type;
	protected int spotsRequired;
	public String getNumberPlate() {
		return this.licensePlate;
	}

	public void setNumberPlate(String licensePlate) {
		this.licensePlate = licensePlate;
	}



}

public class Bike extends Vehicle{

}


public class Car extends Vehicle {
	
}



// public class QueueAlgorithm implements ParkingSpotStrategy {

// 	@Override
// 	public void findParkingSpot(Vehicle v) {

// 	}
// };
