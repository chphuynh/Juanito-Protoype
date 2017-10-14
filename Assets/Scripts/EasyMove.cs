using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using System.Collections;

public class EasyMove : MonoBehaviour
{
    //alternative movement
    public bool smoothMode = false;
    public float walkSpeed = 3;

    //base Movement Related
    public int moveRange;
    private RaycastHit hit;
   
    //Delegate manages a stack of all non player actions that occur
    public delegate void MoveAction();
    public static event MoveAction OnPlayerMove;
    
    //Dialogue
    public GameObject textField;

    //Handles npc interaction
    void Talk(GameObject npc)
    {
        if(npc.GetComponent<DialogueTrigger>()!= null) npc.GetComponent<DialogueTrigger>().TriggerDialogue();
    }
	
    //Handles box interaction
    void MoveBox(GameObject box, int x, int y, int z)
    {
		while (!Physics.Linecast(box.transform.position, box.transform.position + new Vector3(x, y, z)))
        {
            box.transform.Translate(x, y, z);
        }
    }
	void HandleEventTrigger(string trigger) {
		switch(trigger) {
			case "teleport1":
				transform.Translate(new Vector3(5, -1, 0));
				break;
			case "teleport2":
				transform.Translate(new Vector3(-4, 0, 0));
				break;
			default:
				Debug.Log("Not defined.");
				break;
		}
	}
    //regulated call if smooth movement enabled
    void FixedUpdate()
    {
        if (smoothMode)
        {
            GetComponent<Rigidbody>().velocity = new Vector3(Mathf.Lerp(0, Input.GetAxis("Horizontal") * walkSpeed, 1.2f),
                                                 Mathf.Lerp(0, Input.GetAxis("Vertical") * walkSpeed, 1.2f), 0);
        }
    }

    //Input and call to delegate handled in Update
    void Update()
    {
        if (!smoothMode)
        {
            if (Input.GetKeyDown(KeyCode.UpArrow))
            {
                MoveDirection(0, moveRange, 0);
            }
            else if (Input.GetKeyDown(KeyCode.DownArrow))
            {
                MoveDirection(0, -moveRange, 0);
            }
            else if (Input.GetKeyDown(KeyCode.RightArrow))
            {
                MoveDirection(moveRange, 0, 0);
            }
            else if (Input.GetKeyDown(KeyCode.LeftArrow))
            {
                MoveDirection(-moveRange, 0, 0);
            }
        }
    }
    
    //collision based interaction if smooth movement enabled
    void OnCollisionEnter(Collision col)
    {
        if (smoothMode)
        {
			if (col.gameObject.tag == "NPC")
			{
				Talk(col.gameObject);
			}
			else if (col.gameObject.tag == "Box")
			{
				
			}
        }
    }

    void MoveDirection(int x, int y, int z)
    {
		bool continueMove = true;
		
        // Continue Conversation       
        if(FindObjectOfType<DialogueManager>().textField.activeSelf)
        {
            FindObjectOfType<DialogueManager>().DisplayNextSentence();
            return;
        }
        if (Physics.Linecast(transform.position, transform.position + new Vector3(x, y, z), out hit))
        {
			continueMove = false;
            if (hit.collider.gameObject.tag == "NPC")
            {
                Talk(hit.collider.gameObject);
            }
			else if (hit.collider.gameObject.tag == "Box")
			{
				MoveBox(hit.collider.gameObject, x, y, z);
			}
			else if (hit.collider.gameObject.tag == "EventTrigger") {
				HandleEventTrigger(hit.collider.gameObject.GetComponent<EventTrigger>().eventType);
				continueMove = true;
			}
        }
        
		if (continueMove)
        {
            transform.Translate(x, y, z);
            if (OnPlayerMove != null) OnPlayerMove();
        }
    }
}