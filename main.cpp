/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n)   //1
    : value( v ),//2
      name( n )//3
    {
        
    }
    
    int value;
    std::string name;
};

struct TComparator                                //4
{
    T* compare(T* a, T* b) //5
    {
        if( a != nullptr && b != nullptr )
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        
        return nullptr;
    }
};

struct U
{
    float voltageNodeA { 0 }, voltageNodeB { 0 };
    float voltageUpdater( float* updatedVoltage )      //12
    {
        if( updatedVoltage != nullptr )
        {
            std::cout << "U's voltageNodeA value: " << this->voltageNodeA << std::endl;
            this->voltageNodeA = *updatedVoltage;
            std::cout << "U's voltageNodeA updated value: " << this->voltageNodeA << std::endl;
            while( std::abs(this->voltageNodeB - this->voltageNodeA) > 0.001f )
            {
                /*
                 write something that makes the distance between that->voltageNodeB and that->voltageNodeA get smaller
                 */
                this->voltageNodeB += 0.9f * ( this->voltageNodeA - this->voltageNodeB );
            }
            std::cout << "U's voltageNodeB updated value: " << this->voltageNodeB << std::endl;
            return this->voltageNodeB * this->voltageNodeA;
        }
        
        return 0.0f;
    }
};

struct UCalculator
{
    static float voltageUpdater(U* that, float* updatedVoltage )        //10
    {
        if( that != nullptr && updatedVoltage != nullptr )
        {
            std::cout << "U's voltageNodeA value: " << that->voltageNodeA << std::endl;
            that->voltageNodeA = *updatedVoltage;
            std::cout << "U's voltageNodeA updated value: " << that->voltageNodeA << std::endl;
            while( std::abs(that->voltageNodeB - that->voltageNodeA) > 0.001f )
            {
                /*
                 write something that makes the distance between that->voltageNodeB and that->voltageNodeA get smaller
                 */
                that->voltageNodeB += 0.9f * ( that->voltageNodeA - that->voltageNodeB );
            }
            std::cout << "U's voltageNodeB updated value: " << that->voltageNodeB << std::endl;
            return that->voltageNodeB * that->voltageNodeA;
        }
        
        return 0.0f;
    }
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already:
 Make a pull request after you make your first commit
 pin the pull request link and this repl.it link to our DM thread in a single message.
 
 send me a DM to review your pull request when the project is ready for review.
 
 Wait for my code review.
 */

int main()
{
    T student( 4, "Paulo" );                                             //6
    T senior( 55, "Jeremy" );                                             //6
    
    TComparator f;                                            //7
    auto* smaller = f.compare( &student, &senior );                              //8
    
    if( smaller != nullptr )
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "Sorry, you have a null pointer!" << std::endl;
    }
    
    U circuit1;
    float updatedValue = 5.f;
    std::cout << "[static func] circuit1's multiplied values: " << UCalculator::voltageUpdater( &circuit1, &updatedValue ) << std::endl;                  //11
    
    U circuit2;
    std::cout << "[member func] circuit2's multiplied values: " << circuit2.voltageUpdater( &updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
