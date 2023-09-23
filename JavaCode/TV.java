  package JavaCode;

  public class TV {

    public static void main(String[] args) {
      TV tv = new TV("ChangHong", "60inch", "BTV");

      System.out.println(tv);
      tv.changeChannel("NTV");
    }

    private String brand; // 品牌
    private String size; // 尺寸
    private String channel; // 频道

    public TV(){}

    public TV(String brand, String size, String channel){
      this.brand = brand;
      this.size = size;
      this.channel = channel;
    }

    public void setBrand(String brand){
      this.brand = brand;
    }

    public void setSize(String size){
      this.size = size;
    }

    public void setChanne(String channel){
      this.channel = channel;
    }

    public void changeChannel(String channel){ // 切换频道方法
      System.out.println("current channel is " + this.brand + ", switch to " + brand);
      this.channel = channel;  
    }

    @Override
    public String toString(){
      return brand + ", " + size;
    }
  }
