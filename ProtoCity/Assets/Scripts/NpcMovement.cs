using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class NpcMovement : MonoBehaviour {

    public Transform player;
    //number of spaces that can be moved per turn
    public int range = 1;
    private RaycastHit hit;
    //direction to move in 1=east,2=north,3=south,4=west
    public int direction = 1;
    
    public string dialogue;
    //find player
    void Awake()
    {
        player = GameObject.FindGameObjectWithTag("Player").transform;
    }
    //add action to stack
    void OnEnable()
    {
        EasyMove.OnPlayerMove += MoveNPC;
    }
    //remove action from stack
    void OnDisable()
    {
        EasyMove.OnPlayerMove -= MoveNPC;
    }
    //base called action
    void MoveNPC()
    {
        Wander();
    }
    //particular action to perform
    void Wander()
    {

        //First check if player is in range
        if (Physics.Linecast(transform.position, transform.position + new Vector3(range, 0, 0), out hit)
            && hit.collider.gameObject.tag == "Player" && direction == 1)
        {

        }
        else if (Physics.Linecast(transform.position, transform.position + new Vector3(0, range, 0), out hit)
            && hit.collider.gameObject.tag == "Player" && direction == 2)
        {

        }
        else if (Physics.Linecast(transform.position, transform.position + new Vector3(0, -range, 0), out hit)
            && hit.collider.gameObject.tag == "Player" && direction ==3)
        {

        }
        else if (Physics.Linecast(transform.position, transform.position + new Vector3(-range, 0, 0), out hit)
            && hit.collider.gameObject.tag == "Player" && direction == 4)
        {

        }
        //try to move in a direction
        else if (direction == 1)
        {
            if (Physics.Linecast(transform.position, transform.position + new Vector3(range, 0, 0), out hit))
            {
                direction = 4;
                transform.Translate(new Vector3(hit.transform.position.x + -1 - transform.position.x, 0, 0));

            }
            else if (!Physics.Linecast(transform.position, transform.position + new Vector3(range, 0, 0)))
            {
                transform.Translate(range, 0, 0);
            }
        }
        else if (direction == 2)
        {
            if (Physics.Linecast(transform.position, transform.position + new Vector3(0, range, 0), out hit))
            {
                direction = 3;
                transform.Translate(new Vector3(0, hit.transform.position.y + -1 - transform.position.y, 0));
            }
            else if (!Physics.Linecast(transform.position, transform.position + new Vector3(0, range, 0)))
            {
                transform.Translate(0, range, 0);
            }
        }

        else if (direction == 3)
        {
            if (Physics.Linecast(transform.position, transform.position + new Vector3(0, -range, 0), out hit))
            {
                direction = 2;
                transform.Translate(new Vector3(0, hit.transform.position.y + 1 - transform.position.y, 0));
            }
            else if (!Physics.Linecast(transform.position, transform.position + new Vector3(0, -range, 0)))
            {
                transform.Translate(0, -range, 0);
            }
        }

        else if (direction == 4)
        {
            if (Physics.Linecast(transform.position, transform.position + new Vector3(-range, 0, 0), out hit))
            {
                direction = 1;
                transform.Translate(new Vector3(hit.transform.position.x + 1 - transform.position.x, 0, 0));
            }
            else if (!Physics.Linecast(transform.position, transform.position + new Vector3(-range, 0, 0)))
            {
                transform.Translate(-range, 0, 0);
            }
        }
    }
}
