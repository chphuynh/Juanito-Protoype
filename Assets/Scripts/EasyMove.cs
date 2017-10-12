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
    public Text npcText;
    public GameObject textField;
 

    //Disable Dialogue Box
    void Start()
    {
        npcText.text = "";
        textField.SetActive(false);
    }
    //Handles npc interaction
    void Talk(GameObject npc)
    {
                textField.SetActive(true);
                npcText.text = npc.GetComponent<NpcMovement>().dialogue;
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
                npcText.text = "";
                textField.SetActive(false);
                if (Physics.Linecast(transform.position, transform.position + new Vector3(0, moveRange, 0), out hit))
                {
                    if (hit.collider.gameObject.tag == "NPC")
                    {
                        Talk(hit.collider.gameObject);
                    }
                }
                else if (!Physics.Linecast(transform.position, transform.position + new Vector3(0, moveRange, 0)))
                {
                    transform.Translate(0, moveRange, 0);
                    if (OnPlayerMove != null) OnPlayerMove();
                }
            }
            else if (Input.GetKeyDown(KeyCode.DownArrow))
            {
                npcText.text = "";
                textField.SetActive(false);
                if (Physics.Linecast(transform.position, transform.position + new Vector3(0, -moveRange, 0), out hit))
                {
                    if (hit.collider.gameObject.tag == "NPC")
                    {
                        Talk(hit.collider.gameObject);
                    }
                }
                else if (!Physics.Linecast(transform.position, transform.position + new Vector3(0, -moveRange, 0)))
                {
                    transform.Translate(0, -moveRange, 0);
                    if (OnPlayerMove != null) OnPlayerMove();
                }
            }
            else if (Input.GetKeyDown(KeyCode.RightArrow))
            {
                npcText.text = "";
                textField.SetActive(false);
                if (Physics.Linecast(transform.position, transform.position + new Vector3(moveRange, 0, 0), out hit))
                {
                    if (hit.collider.gameObject.tag == "NPC")
                    {
                        Talk(hit.collider.gameObject);
                    }
                }
                else if (!Physics.Linecast(transform.position, transform.position + new Vector3(moveRange, 0, 0)))
                {
                    transform.Translate(moveRange, 0, 0);
                    if (OnPlayerMove != null) OnPlayerMove();
                }
            }
            else if (Input.GetKeyDown(KeyCode.LeftArrow))
            {
                npcText.text = "";
                textField.SetActive(false);
                if (Physics.Linecast(transform.position, transform.position + new Vector3(-moveRange, 0, 0), out hit))
                {
                    if (hit.collider.gameObject.tag == "NPC")
                    {
                        Talk(hit.collider.gameObject);
                    }
                }
                else if (!Physics.Linecast(transform.position, transform.position + new Vector3(-moveRange, 0, 0)))
                {
                    transform.Translate(-moveRange, 0, 0);
                    if (OnPlayerMove != null) OnPlayerMove();
                }
            }
        }
    }
    //collision based interaction if smooth movement enabled
    void OnCollisionEnter(Collision col)
    {
        if (smoothMode && col.gameObject.tag == "NPC")
        {
            Talk(col.gameObject);
        }
    }
}