using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class EventTrigger : MonoBehaviour {

    public int eventType;
    
    void Start()
    {
		if (eventType == null) {
			eventType = -1;
		}
	}
}
