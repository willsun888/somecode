public class ProducerAndConsumerDemo{  
    private LinkedList<Object> myList =new LinkedList<Object>();  
    private int MAX = 10;  
      
    public ProducerAndConsumerDemo(){  
    }  
      
    public void start(){  
            new Producer().start();  
            new Consumer().start();  
    }  
      
    public static void main(String[] args) throws Exception{  
        ProducerAndConsumerDemo s1 = new ProducerAndConsumerDemo();  
        s1.start();  
    }  
      
    class Producer extends Thread{          
        public void run(){  
            while(true){  
                synchronized(myList){  
                    try{  
                        while(myList.size() == MAX)...{  
                            System.out.println("warning: it's full!");  
                            myList.wait();  
                        }  
                        Object o = new Object();  
                        if(myList.add(o)){  
                            System.out.println("Producer: " + o);  
                            myList.notify();  
                        }  
                    }catch(InterruptedException ie){  
                        System.out.println("producer is interrupted!");  
                    }  
                }  
            }  
        }  
    }  
      
    class Consumer extends Thread{  
        public void run(){  
            while(true){  
                synchronized(myList){  
                    try{  
                        while(myList.size() == 0){  
                            System.out.println("warning: it's empty!");  
                            myList.wait();  
                        }  
                        Object o = myList.removeLast();  
                        System.out.println("Consumer: " + o);  
                        myList.notify();  
                    }catch(InterruptedException ie)...{  
                        System.out.println("consumer is interrupted!");  
                    }  
                }  
            }  
        }  
    }  
      
} 