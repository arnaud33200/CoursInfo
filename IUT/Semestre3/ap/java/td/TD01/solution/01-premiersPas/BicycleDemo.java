class BicycleDemo {
    public static void main(String[] args) {
	
	// Create two different Bicycle objects
	Bicycle bike1 = new Bicycle(1,20,10);
	Bicycle bike2 = new Bicycle(2,40,60);
	
	// Invoke methods on those objects
	bike1.setCadence(50);
	bike1.speedUp(10);
	bike1.setGear(2);
	bike1.printStates();
	
	bike2.setCadence(50);
	bike2.speedUp(10);
	bike2.setGear(3);
	bike2.setCadence(60);
	bike2.speedUp(10);
	bike2.setGear(4);
	bike2.printStates();
    }
}

