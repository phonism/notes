package StrategyPattern;

public class MiniDuckSimulator {
	
	public static void main(String[] args) {
		Duck mallard = new MallardDuck();
		mallard.performQuack();
		mallard.performmFly();
		
		Duck model = new ModelDuck();
		model.performmFly();
		model.setFlyBehavior(new FlyRocketPowered());
		model.performmFly();
	}

}
