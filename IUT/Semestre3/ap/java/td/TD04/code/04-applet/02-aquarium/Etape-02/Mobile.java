import java.util.*;
import java.awt.*;

public interface Mobile
{
    boolean move();
    Point target(Collection<AquariumItem> neighbors);
}